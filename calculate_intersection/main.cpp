#include <iostream>

// ������ ã�� �Լ�
std::pair<double, double> findIntersection(double m1, double c1, double m2, double c2) {
    // ���� �������� Ǯ� ������ x ��ǥ�� ã��
    double x = (c2 - c1) / (m1 - m2);

    // x ��ǥ�� �� ������ �����Ŀ� �����Ͽ� ������ y ��ǥ�� ã��
    double y = m1 * x + c1;

    return std::make_pair(x, y);
}

int main() {
    // ù ��° ������ ������ �� ��
    double lat1_1 = 36.623316, lon1_1 = 127.435036;
    double lat1_2 = 36.623618, lon1_2 = 127.434816;

    // �� ��° ������ ������ �� ��
    double lat2_1 = 36.623710, lon2_1 = 127.434521;
    double lat2_2 = 36.623558, lon2_2 = 127.434065;

    // ù ��° ������ ����� y ���� ���
    double m1 = (lat1_2 - lat1_1) / (lon1_2 - lon1_1);
    double c1 = lat1_1 - m1 * lon1_1;

    // �� ��° ������ ����� y ���� ���
    double m2 = (lat2_2 - lat2_1) / (lon2_2 - lon2_1);
    double c2 = lat2_1 - m2 * lon2_1;

    // ������ ��ǥ ���
    std::pair<double, double> intersection = findIntersection(m1, c1, m2, c2);

    // ��� ��� (�Ҽ��� 6�ڸ�����)
    printf("Intersection Latitude: %.6f, Longitude: %.6f\n", intersection.first, intersection.second);

    return 0;
}
