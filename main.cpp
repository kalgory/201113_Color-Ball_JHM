//
//  main.cpp
//  Color-Ball
//
//  Created by 정현민 on 2020/11/13.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Ball
{
  int color;
  int index;
};

vector<int> getOutput(int number, vector<int>& color_vec, vector<int>& size_vec)
{
  map<int, vector<Ball>> size_ball_vec_map;
  for(int i = 0; i < number; i++)
  {
    size_ball_vec_map[size_vec[i]].push_back({color_vec[i], i});
  }
  
  int sum = 0;
  vector<int> output_vec(number);
  map<int, int> color_size_map;
  for(const auto& [size, ball_vec] : size_ball_vec_map)
  {
    for(const auto& ball : ball_vec)
    {
      output_vec[ball.index] = sum - color_size_map[ball.color];
    }
    for(const auto& ball : ball_vec)
    {
      sum += size;
      color_size_map[ball.color] += size;
    }
  }
  
  return output_vec;
}

int main()
{
  int number;
  cin >> number;
  
  vector<int> color_vec(number);
  vector<int> size_vec(number);
  
  for(int i = 0; i < number; i++)
  {
    scanf("%d %d", &color_vec[i], &size_vec[i]);
//    cin >> color_vec[i] >> size_vec[i];
  }
  
  vector<int> output_vec = getOutput(number, color_vec, size_vec);
  for(int i = 0; i < number; i++)
  {
    printf("%d\n", output_vec[i]);
//    cout << output_vec[i] << endl;
  }
  
  return 0;
}
