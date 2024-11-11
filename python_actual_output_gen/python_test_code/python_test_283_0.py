x,a,b=map(int,input().split())
print("dangerous" if (a+x)<b else "delicious" if a>b else "safe")