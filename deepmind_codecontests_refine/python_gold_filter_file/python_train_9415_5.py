
lis = list(map(int,input().split()))
songs = list(map(int,input().split()))

d = lis[1]
time = 0
count = 0
joke = 5
n = len(songs)
song_time = sum(songs) + (n-1)*10
if song_time > d:
    print (-1)
else:
    spare_time = (n-1) * 10 / 5
    count += spare_time
    rest_time = d - song_time
    count += rest_time // 5
    print (int(count))