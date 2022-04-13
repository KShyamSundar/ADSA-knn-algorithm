#include <bits/stdc++.h>
using namespace std;
 
struct Point
{
    double x, y;     // Co-ordinate of point
    double distance; // Distance from test point
};
 
//sort an array of points by increasing
// order of distance
bool comparison(Point a, Point b)
{
    return (a.distance < b.distance);
}
 

void k_nearest_neighbours(Point arr[], long long n, long long k, Point p)
{
    // Fill distances of all points from p
    for (long long i = 0; i < n; i++)
        arr[i].distance =
            sqrt((arr[i].x - p.x) * (arr[i].x - p.x) +
                 (arr[i].y - p.y) * (arr[i].y - p.y));
 
    // Sort the Points by distance from p
    sort(arr, arr+n, comparison);
 
    cout<<endl;
    for (long long i = 0; i < k; i++)
    {
        cout<<"( "<<arr[i].x<<","<<arr[i].y<<" )"<<"  ";
    }
    cout<<endl;  
}
 
//main
int main()
{
    long long n = 20; 
    Point arr[n]  = { { 1,12}, { 2,5}, { 5,3}, {3,2}, {3,6}, {1.5, 9},{7,2},{6,1},{3.8,3},{3,10},
                        {5.6, 4}, {4,2}, {3.5, 8}, {2,11}, {2,5},{2,9}, {1,7}, { 100, 8}, { 1, 0}, { 50, 9}};
    //Testing Point
    Point p;
    cout<<"\nEnter the test point : ";
    cin>>p.x>>p.y;
 
    long long k;
    cout<<"\nEnter the k value : ";
    cin>>k;

    cout<<"k-nearest neighbours of the given test point : \n";
    k_nearest_neighbours(arr, n, k, p);
    cout<<endl;

    /////////////////////////////////////
    //testing for large n
    cout<<"\nTesting for large value of n \n---------------------------------------\n";
    n = 500000;
    Point* B = new Point[n];

    for (long long i = 0; i < n; ++i) 
    {
        B[i].x  = (double)rand() / RAND_MAX;
        B[i].y  = (double)rand() / RAND_MAX;
    }


    //test point
    Point test;
    double diff;
    test.x = (double)rand() / RAND_MAX;
    test.y = (double)rand() / RAND_MAX;

    //KNN query
	cout<<"k-nearest neighbours of the given test point : \n";
    clock_t begin = clock();    
        k_nearest_neighbours(B, n, k, p);
    clock_t end = clock();

    diff = double(end - begin) / CLOCKS_PER_SEC;
    cout << "KNN search time for one random point:\n" << diff << "s" << endl;
}
