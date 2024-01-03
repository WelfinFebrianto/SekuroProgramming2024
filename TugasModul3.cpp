#include <iostream>
#include <vector>

// Class Matrix
class Matrix {
private:
    std::vector<std::vector<float>> data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data.resize(numRows, std::vector<float>(numCols, 0.0));
    }

    Matrix(std::initializer_list<std::initializer_list<float>> values) {
        rows = values.size();
        cols = values.begin()->size();
        data.reserve(rows);

        for (const auto& row : values) {
            data.push_back(row);
        }
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    // Tambahkan fungsi untuk mengakses data
    const std::vector<std::vector<float>>& getData() const {
        return data;
    }
};

// Class Swerve yang terhubung dengan class Matrix
class Swerve {
private:
    float r; // Jarak dari pusat chasis ke roda
    Matrix wheelMatrix; // Matriks transformasi roda
    Matrix velocityMatrix; // Matriks kecepatan dan omega
    Matrix wheelVelocities; // Vektor kecepatan roda [v1x, v1y, v2x, v2y, v3x, v3y, v4x, v4y]
    Matrix robotVelocity; // Vektor kecepatan robot [vx, vy, omega]

public:
    Swerve(float radius) : r(radius), wheelMatrix({
        {1, 0, -r}, {0, 1, r}, {1, 0, -r}, {0, 1, r},
        {1, 0, -r}, {0, 1, r}, {1, 0, -r}, {0, 1, r}
    }), velocityMatrix({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    }), wheelVelocities(8, 1), robotVelocity(3, 1) {}

    // Fungsi untuk menghitung nilai vnx dan vny pada roda ke-n
    void velocityCommand(float vx, float vy, float omega, int n) {
        Matrix input = {{vx}, {vy}, {omega}};
        wheelVelocities = wheelMatrix * input;

        // Set nilai vnx dan vny pada roda ke-n
        float vnx = wheelVelocities.getData()[2 * n][0];
        float vny = wheelVelocities.getData()[2 * n + 1][0];

        std::cout << "Wheel " << n << " velocity: (" << vnx << ", " << vny << ")\n";
    }

    // Fungsi untuk mengupdate pose robot
    void updatePose(float deltaTime) {
        robotVelocity = velocityMatrix * wheelVelocities;

        // TODO: Implementasikan perhitungan pose berdasarkan nilai robotVelocity
        // x_k+1 = x_k + v_x * delta_time
        // y_k+1 = y_k + v_y * delta_time
        // theta_k+1 = theta_k + omega * delta_time

        std::cout << "Updated Robot Pose: (" << robotVelocity.getData()[0][0] << ", " << robotVelocity.getData()[1][0] << ", " << robotVelocity.getData()[2][0] << ")\n";
    }
};

int main() {
    // Membuat objek Swerve dengan radius roda 0.26363 meter
    Swerve mySwerve(0.26363);

    // Memanggil fungsi velocityCommand untuk roda ke-1
    mySwerve.velocityCommand(1.0, 0.0, 0.0, 0);

    // Memanggil fungsi updatePose
    mySwerve.updatePose(0.1);

    return 0;
}
