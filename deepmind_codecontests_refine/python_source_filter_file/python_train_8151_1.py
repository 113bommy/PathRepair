n, k, l, c, d, p, nl, np=map(int,input().split())
ans1=(k*l)//3
ans2=c*d
ans3=p//np
final=min(ans1,ans2,ans3)//nl
print(final)