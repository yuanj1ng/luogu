#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

struct Point{
    double x;
    double y;
};

double cal_dist(Point a, Point b){
    return pow((a.x-b.x),2) + pow((a.y-b.y),2);
}

bool cmp_x(Point a, Point b){
    return a.x < b.x;
}

bool cmp_y(Point a, Point b){
    return a.y < b.y;
}

double find_min_dist(const std::vector<Point> &point_v,int l_ind,int r_ind){
    double min_dist = std::numeric_limits<double>::max();
    if(r_ind-l_ind <=3){ 
        for(int i = l_ind;i<=r_ind;i++){
            for(int j=i+1;j<=r_ind;j++){
                double temp = cal_dist(point_v[i],point_v[j]);
                if(temp<min_dist){
                    min_dist = temp;
                }
            }
        }
        return min_dist;
    }
    else {
    int mid = (r_ind + l_ind)/2;
    double mid_x = point_v[mid].x;
    double l_dist = find_min_dist(point_v,l_ind,mid);
    double r_dist = find_min_dist(point_v,mid+1,r_ind);
    min_dist = std::min(l_dist,r_dist);
    std::vector<Point> strip_points;
    for(int i = l_ind;i<=r_ind;i++){
        if(pow(point_v[i].x - mid_x,2) < min_dist){
            strip_points.push_back(point_v[i]);
        }
    }
    std::sort(strip_points.begin(), strip_points.end(),cmp_y);
    for(int i=0;i<strip_points.size();i++){
        for(int j=i+1;j<strip_points.size();j++){
            if (pow(strip_points[j].y - strip_points[i].y, 2) >= min_dist) {
            break;
        }
        // 更新最小距离
        min_dist = std::min(min_dist, cal_dist(strip_points[i], strip_points[j]));   
        }
    }
    return min_dist;
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<Point> point_v(n);
    for(int i =0;i<n;i++){
    Point point;
    std::cin >> point.x >> point.y;
    point_v[i] = point;
    }
    std::sort(point_v.begin(),point_v.end(),cmp_x);
    double ans = find_min_dist(point_v,0,n-1);
    std::cout << std::fixed << std::setprecision(4) << sqrt(ans) << std::endl;
    return 0;
}