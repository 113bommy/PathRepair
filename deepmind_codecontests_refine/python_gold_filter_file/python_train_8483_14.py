a = list(map(float,input().strip().split()))[:2]
print(int(min(a)),int(max((a[0]-min(a))/2,(a[1]-min(a))/2)))