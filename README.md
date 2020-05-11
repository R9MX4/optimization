## Optimization

<br>1.Open AUTOCAD/Map1.dwg in AutoCAD\<br>
Export the coordinates of all subway stations and mountain

2.Random choose 30 stations\<br>
Input the coordinates of mountain and selected stations to file DisCal/Debug/Mountain.txt and DisCal/Debug/Station.txt

3.Run DisCal/Debug/DisCal.exe, get results in DisCal/Debug/Distance.txt

4.Copy Distance.txt to MST/Distance.txt

Run MST.m in MATLAB, get the Minimum spanning tree

Example:
T =

     1    24     2    14    12     5     1    19    10    10    19    20    27    28    28    25    30    30    21    18    26     4    13     9    16    23     7    26    13
    24     2    14    12     5    22    19    10    20     3     8    27    28    11    25    30    15    21    18    26     4    13     9    16    23     7     6    29    17
total_length = 50.8136

T means Connect point 1 to 24, 24 to 2, ect..

5.Input the coordinates of selected stations to AUTOCAD/point.txt

Input the coordinates of Minimum spanning tree to AUTOCAD/line.txt

Open AUTOCAD/Map2.dwg in AutoCAD

Put point.txt and line.txt into command line console
