#include <iostream>

// 교점을 찾는 함수
std::pair<double, double> findIntersection(double m1, double c1, double m2, double c2) {
    // 연립 방정식을 풀어서 교점의 x 좌표를 찾음
    double x = (c2 - c1) / (m1 - m2);

    // x 좌표를 각 직선의 방정식에 대입하여 교점의 y 좌표를 찾음
    double y = m1 * x + c1;

    return std::make_pair(x, y);
}

int main() {
    // 첫 번째 직선을 지나는 두 점
    double lat1_1 = 36.623316, lon1_1 = 127.435036;
    double lat1_2 = 36.623618, lon1_2 = 127.434816;

    // 두 번째 직선을 지나는 두 점
    double lat2_1 = 36.623710, lon2_1 = 127.434521;
    double lat2_2 = 36.623558, lon2_2 = 127.434065;

    // 첫 번째 직선의 기울기와 y 절편 계산
    double m1 = (lat1_2 - lat1_1) / (lon1_2 - lon1_1);
    double c1 = lat1_1 - m1 * lon1_1;

    // 두 번째 직선의 기울기와 y 절편 계산
    double m2 = (lat2_2 - lat2_1) / (lon2_2 - lon2_1);
    double c2 = lat2_1 - m2 * lon2_1;

    // 교점의 좌표 계산
    std::pair<double, double> intersection = findIntersection(m1, c1, m2, c2);

    // 결과 출력 (소수점 6자리까지)
    printf("Intersection Latitude: %.6f, Longitude: %.6f\n", intersection.first, intersection.second);

    return 0;
}
