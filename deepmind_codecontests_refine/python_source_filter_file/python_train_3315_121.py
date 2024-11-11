a,b=map(int,input().split())
print(["P","Imp"][a%3==b%3 and a%3==1 or a%3==2]+"ossible")