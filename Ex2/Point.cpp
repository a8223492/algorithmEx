//class Point {
//    //������
//    int x;
//
//    //������
//    int y;
//
//    /**
//    * �����������֮��ľ���
//    * @return
//    */
//    public static double distance(Point ri, Point le) {
//        return Math.sqrt((ri.x - le.x) * (ri.x - le.x) + (ri.y - le.y) * (ri.y - le.y));
//    }
//}
///**
//  * ʹ�������������̵��
//  * @param list ���б�
//  * @param begin ��ʼ����
//  * @param end ��������
//  * @return ��̵��
//  */
//private static Object[] simDistance(Point[] list, int begin, int end) {
//    //�洢�����Լ�����
//    Object[] result = new Object[3];
//    result[0] = Double.MAX_VALUE;
//    for (int i = begin; i <= end; i++) {
//        for (int j = i + 1; j <= end; j++) {
//            //���ÿһ�Ե�ľ���
//            double distance = Point.distance(list[i], list[j]);
//            if ((double)result[0] >= distance) {
//                result[0] = distance;
//                result[1] = list[i];
//                result[2] = list[j];
//            }
//        }
//    }
//    return result;
//}
