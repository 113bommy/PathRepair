import math

print(math.tan(math.pi/3))

def main():
    n=int(input())
    p=math.pi
    tht=p/n
    ans=1/(math.tan(tht/2))
    print(ans)

if __name__=="__main__":
    t=int(input())
    for i in range(t):
        main()





