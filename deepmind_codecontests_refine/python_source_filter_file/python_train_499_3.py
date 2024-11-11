a,b,c,x,y=map(int, input().split())

ans = min(a*x+b*y, c*max(x,y)*2, c*x*2+max(0,(y-x)*b), c*y*2+max((x-y)*a)*a)

print(ans)