x,y,z,t1,t2,t3 = map(int, input().split())
s=abs(x-y)*t1
e=abs(x-z)*t2+2+abs(x-y)*t2+1
print("YES" if e<=s else "NO")