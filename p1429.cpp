#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>

struct Point{
    double x;
    double y;
};

double cal_dist(Point a, Point b){
    return sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
}

bool cmp(Point a, Point b){
    return a.x < b.x;
}

double find_min_dist(const std::vector<Point> &point_v,int l_ind,int r_ind){
    double min_dist = std::numeric_limits<double>::max();
    if(r_ind-l_ind <=3){
        for(int i=l_ind;i<=r_ind;++i){
            for(int j=i+1;j<=r_ind;++j){
                min_dist = std::min(cal_dist(point_v[i],point_v[j]),min_dist);
            }
        }
        return min_dist;
    }
    int mid = (r_ind + l_ind)/2;
    double mid_x = point_v[mid].x;
    double l_dist = find_min_dist(point_v,l_ind,mid);
    double r_dist = find_min_dist(point_v,mid+1,r_ind);
    min_dist = std::min(l_dist,r_dist);
    std::vector<Point> strip_point;
    for(int i=l_ind;i<=r_ind;++i){
        if(std::abs(point_v[i].x-mid_x)<min_dist){
            strip_point.push_back(point_v[i]);
        }
    }
    for(size_t i=0;i<strip_point.size();++i){
        for(size_t j=i+1;j<strip_point.size();++j){
        if(std::abs(strip_point[i].y-strip_point[j].y)>min_dist){
            break;
        }
        min_dist = std::min(cal_dist(point_v[i],point_v[j]),min_dist);
        }
    }
    return min_dist;
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
    std::sort(point_v.begin(),point_v.end(),cmp);
    double ans = find_min_dist(point_v,0,n-1);
    std::cout << std::fixed << std::setprecision(4) << ans << std::endl;
    return 0;
}