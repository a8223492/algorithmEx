//class Point {
//    //横坐标
//    int x;
//
//    //纵坐标
//    int y;
//
//    /**
//    * 求解两个坐标之间的距离
//    * @return
//    */
//    public static double distance(Point ri, Point le) {
//        return Math.sqrt((ri.x - le.x) * (ri.x - le.x) + (ri.y - le.y) * (ri.y - le.y));
//    }
//}
///**
//  * 使用蛮力法求解最短点距
//  * @param list 点列表
//  * @param begin 开始索引
//  * @param end 结束索引
//  * @return 最短点距
//  */
//private static Object[] simDistance(Point[] list, int begin, int end) {
//    //存储最近点对及距离
//    Object[] result = new Object[3];
//    result[0] = Double.MAX_VALUE;
//    for (int i = begin; i <= end; i++) {
//        for (int j = i + 1; j <= end; j++) {
//            //求解每一对点的距离
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
