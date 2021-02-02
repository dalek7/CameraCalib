# Camera Calibration
Tested under

```
2021/2/2
OpenCV 3.4.13 (should work with any 3.x)
Visual Studio 2017 (VS 15)
```

```
2019/5/22
OpenCV 3.2 (should work with 3.x)
Visual Studio 2015
```

## Examples
* In progress
<img src='screenshots/image02.png' />

* Undistorted
<img src='screenshots/image01.png' />

* Comparison
<img src='examples/anigif_0.gif' width=500px />

* Run example
```
Directory ../out_20210202_183105_936000was successfully created
Loaded configuration file: "default.xml"
found 59 pic file(s)
../examples/20210202_ao/20210202_153203.311_.jpg
...
../examples/20210202_ao/20210202_154119.527_.jpg
inputType = 1
boardSize = 9 x 6
0       640 x 480 x 3... OK
../out_20210202_183105_936000/0.jpg
1       640 x 480 x 3... OK
../out_20210202_183105_936000/1.jpg
2       640 x 480 x 3... OK
../out_20210202_183105_936000/2.jpg
3       640 x 480 x 3... OK
../out_20210202_183105_936000/3.jpg
4       640 x 480 x 3... OK
../out_20210202_183105_936000/4.jpg
5       640 x 480 x 3... OK
../out_20210202_183105_936000/5.jpg
6       640 x 480 x 3... OK
../out_20210202_183105_936000/6.jpg
7       640 x 480 x 3... OK
../out_20210202_183105_936000/7.jpg
8       640 x 480 x 3... OK
../out_20210202_183105_936000/8.jpg
9       640 x 480 x 3... OK
../out_20210202_183105_936000/9.jpg
10      640 x 480 x 3... OK
../out_20210202_183105_936000/10.jpg
11      640 x 480 x 3... OK
../out_20210202_183105_936000/11.jpg
12      640 x 480 x 3... OK
../out_20210202_183105_936000/12.jpg
13      640 x 480 x 3... OK
../out_20210202_183105_936000/13.jpg
14      640 x 480 x 3... OK
../out_20210202_183105_936000/14.jpg
15      640 x 480 x 3... OK
../out_20210202_183105_936000/15.jpg
16      640 x 480 x 3... OK
../out_20210202_183105_936000/16.jpg
17      640 x 480 x 3... OK
../out_20210202_183105_936000/17.jpg
18      640 x 480 x 3... OK
../out_20210202_183105_936000/18.jpg
19      640 x 480 x 3... OK
../out_20210202_183105_936000/19.jpg
20      640 x 480 x 3... OK
../out_20210202_183105_936000/20.jpg
21      640 x 480 x 3... OK
../out_20210202_183105_936000/21.jpg
22      640 x 480 x 3... OK
../out_20210202_183105_936000/22.jpg
23      640 x 480 x 3... OK
../out_20210202_183105_936000/23.jpg
24      640 x 480 x 3... OK
../out_20210202_183105_936000/24.jpg
25      640 x 480 x 3... OK
../out_20210202_183105_936000/25.jpg
26      640 x 480 x 3... OK
../out_20210202_183105_936000/26.jpg
27      640 x 480 x 3... OK
../out_20210202_183105_936000/27.jpg
28      640 x 480 x 3... OK
../out_20210202_183105_936000/28.jpg
29      640 x 480 x 3... OK
../out_20210202_183105_936000/29.jpg
30      640 x 480 x 3... OK
../out_20210202_183105_936000/30.jpg
31      640 x 480 x 3... OK
../out_20210202_183105_936000/31.jpg
32      640 x 480 x 3... OK
../out_20210202_183105_936000/32.jpg
33      640 x 480 x 3... OK
../out_20210202_183105_936000/33.jpg
34      640 x 480 x 3... OK
../out_20210202_183105_936000/34.jpg
35      640 x 480 x 3Re-projection error reported by calibrateCamera: 0.386884
Calibration succeeded. avg re projection error = 0.386884
... OK
../out_20210202_183105_936000/35.jpg
36      640 x 480 x 3... OK
../out_20210202_183105_936000/36.jpg
37      640 x 480 x 3... OK
../out_20210202_183105_936000/37.jpg
38      640 x 480 x 3... OK
../out_20210202_183105_936000/38.jpg
39      640 x 480 x 3
../out_20210202_183105_936000/39.jpg
40      640 x 480 x 3
../out_20210202_183105_936000/40.jpg
41      640 x 480 x 3
../out_20210202_183105_936000/41.jpg
42      640 x 480 x 3... OK
../out_20210202_183105_936000/42.jpg
43      640 x 480 x 3... OK
../out_20210202_183105_936000/43.jpg
44      640 x 480 x 3
../out_20210202_183105_936000/44.jpg
45      640 x 480 x 3... OK
../out_20210202_183105_936000/45.jpg
46      640 x 480 x 3... OK
../out_20210202_183105_936000/46.jpg
47      640 x 480 x 3... OK
../out_20210202_183105_936000/47.jpg
48      640 x 480 x 3
../out_20210202_183105_936000/48.jpg
49      640 x 480 x 3... OK
../out_20210202_183105_936000/49.jpg
50      640 x 480 x 3... OK
../out_20210202_183105_936000/50.jpg
51      640 x 480 x 3
../out_20210202_183105_936000/51.jpg
52      640 x 480 x 3... OK
../out_20210202_183105_936000/52.jpg
53      640 x 480 x 3
../out_20210202_183105_936000/53.jpg
54      640 x 480 x 3
../out_20210202_183105_936000/54.jpg
55      640 x 480 x 3... OK
../out_20210202_183105_936000/55.jpg
56      640 x 480 x 3... OK
../out_20210202_183105_936000/56.jpg
57      640 x 480 x 3... OK
../out_20210202_183105_936000/57.jpg
58      640 x 480 x 3... OK
../out_20210202_183105_936000/58.jpg
../out_20210202_183105_936000/0_undist.jpg
../out_20210202_183105_936000/0_.jpg
../out_20210202_183105_936000/1_undist.jpg
../out_20210202_183105_936000/1_.jpg
../out_20210202_183105_936000/2_undist.jpg
../out_20210202_183105_936000/2_.jpg
../out_20210202_183105_936000/3_undist.jpg
../out_20210202_183105_936000/3_.jpg
../out_20210202_183105_936000/4_undist.jpg
../out_20210202_183105_936000/4_.jpg
../out_20210202_183105_936000/5_undist.jpg
../out_20210202_183105_936000/5_.jpg
../out_20210202_183105_936000/6_undist.jpg
../out_20210202_183105_936000/6_.jpg
../out_20210202_183105_936000/7_undist.jpg
../out_20210202_183105_936000/7_.jpg
../out_20210202_183105_936000/8_undist.jpg
../out_20210202_183105_936000/8_.jpg
../out_20210202_183105_936000/9_undist.jpg
../out_20210202_183105_936000/9_.jpg
../out_20210202_183105_936000/10_undist.jpg
../out_20210202_183105_936000/10_.jpg
../out_20210202_183105_936000/11_undist.jpg
../out_20210202_183105_936000/11_.jpg
../out_20210202_183105_936000/12_undist.jpg
../out_20210202_183105_936000/12_.jpg
../out_20210202_183105_936000/13_undist.jpg
../out_20210202_183105_936000/13_.jpg
../out_20210202_183105_936000/14_undist.jpg
../out_20210202_183105_936000/14_.jpg
../out_20210202_183105_936000/15_undist.jpg
../out_20210202_183105_936000/15_.jpg
../out_20210202_183105_936000/16_undist.jpg
../out_20210202_183105_936000/16_.jpg
../out_20210202_183105_936000/17_undist.jpg
../out_20210202_183105_936000/17_.jpg
../out_20210202_183105_936000/18_undist.jpg
../out_20210202_183105_936000/18_.jpg
../out_20210202_183105_936000/19_undist.jpg
../out_20210202_183105_936000/19_.jpg
../out_20210202_183105_936000/20_undist.jpg
../out_20210202_183105_936000/20_.jpg
../out_20210202_183105_936000/21_undist.jpg
../out_20210202_183105_936000/21_.jpg
../out_20210202_183105_936000/22_undist.jpg
../out_20210202_183105_936000/22_.jpg
../out_20210202_183105_936000/23_undist.jpg
../out_20210202_183105_936000/23_.jpg
../out_20210202_183105_936000/24_undist.jpg
../out_20210202_183105_936000/24_.jpg
../out_20210202_183105_936000/25_undist.jpg
../out_20210202_183105_936000/25_.jpg
../out_20210202_183105_936000/26_undist.jpg
../out_20210202_183105_936000/26_.jpg
../out_20210202_183105_936000/27_undist.jpg
../out_20210202_183105_936000/27_.jpg
../out_20210202_183105_936000/28_undist.jpg
../out_20210202_183105_936000/28_.jpg
../out_20210202_183105_936000/29_undist.jpg
../out_20210202_183105_936000/29_.jpg
../out_20210202_183105_936000/30_undist.jpg
../out_20210202_183105_936000/30_.jpg
../out_20210202_183105_936000/31_undist.jpg
../out_20210202_183105_936000/31_.jpg
../out_20210202_183105_936000/32_undist.jpg
../out_20210202_183105_936000/32_.jpg
../out_20210202_183105_936000/33_undist.jpg
../out_20210202_183105_936000/33_.jpg
../out_20210202_183105_936000/34_undist.jpg
../out_20210202_183105_936000/34_.jpg
../out_20210202_183105_936000/35_undist.jpg
../out_20210202_183105_936000/35_.jpg
../out_20210202_183105_936000/36_undist.jpg
../out_20210202_183105_936000/36_.jpg
../out_20210202_183105_936000/37_undist.jpg
../out_20210202_183105_936000/37_.jpg
../out_20210202_183105_936000/38_undist.jpg
../out_20210202_183105_936000/38_.jpg
../out_20210202_183105_936000/39_undist.jpg
../out_20210202_183105_936000/39_.jpg
../out_20210202_183105_936000/40_undist.jpg
../out_20210202_183105_936000/40_.jpg
../out_20210202_183105_936000/41_undist.jpg
../out_20210202_183105_936000/41_.jpg
../out_20210202_183105_936000/42_undist.jpg
../out_20210202_183105_936000/42_.jpg
../out_20210202_183105_936000/43_undist.jpg
../out_20210202_183105_936000/43_.jpg
../out_20210202_183105_936000/44_undist.jpg
../out_20210202_183105_936000/44_.jpg
../out_20210202_183105_936000/45_undist.jpg
../out_20210202_183105_936000/45_.jpg
../out_20210202_183105_936000/46_undist.jpg
../out_20210202_183105_936000/46_.jpg
../out_20210202_183105_936000/47_undist.jpg
../out_20210202_183105_936000/47_.jpg
../out_20210202_183105_936000/48_undist.jpg
../out_20210202_183105_936000/48_.jpg
../out_20210202_183105_936000/49_undist.jpg
../out_20210202_183105_936000/49_.jpg
../out_20210202_183105_936000/50_undist.jpg
../out_20210202_183105_936000/50_.jpg
../out_20210202_183105_936000/51_undist.jpg
../out_20210202_183105_936000/51_.jpg
../out_20210202_183105_936000/52_undist.jpg
../out_20210202_183105_936000/52_.jpg
../out_20210202_183105_936000/53_undist.jpg
../out_20210202_183105_936000/53_.jpg
../out_20210202_183105_936000/54_undist.jpg
../out_20210202_183105_936000/54_.jpg
../out_20210202_183105_936000/55_undist.jpg
../out_20210202_183105_936000/55_.jpg
../out_20210202_183105_936000/56_undist.jpg
../out_20210202_183105_936000/56_.jpg
../out_20210202_183105_936000/57_undist.jpg
../out_20210202_183105_936000/57_.jpg
../out_20210202_183105_936000/58_undist.jpg
../out_20210202_183105_936000/58_.jpg
```