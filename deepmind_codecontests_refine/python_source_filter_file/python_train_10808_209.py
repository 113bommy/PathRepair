a,b,c,d=map(int,input().split())
print('YNeos'[abs(c-a)>=d and max(abs(b-a),abs(c-b))>d::2])