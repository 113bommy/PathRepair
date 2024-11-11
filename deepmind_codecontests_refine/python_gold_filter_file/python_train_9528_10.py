import  sys

n=int(sys.stdin.readline())

ret=int(((n+4)*(n+3)*((n+2)**2)*((n+1)**2)*(n**2))//720)

print(ret)