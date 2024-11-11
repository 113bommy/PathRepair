A,B=map(int,input().split())
import fraction
print(int((A*B)/fraction.gcd(A,B)))