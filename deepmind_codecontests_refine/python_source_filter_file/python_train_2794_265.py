a,b,c=map(int,input().split())
print(print 'A' if max(abs(b-a),abs(c-a))==abs(b-a) else 'B')