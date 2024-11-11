n=int(input())
for i in range (n):
    a,b,c=input().split()
    print (int((min(int(a),int(b),(int(a)+int(b)+int(c))/3))))
            
