def solution(l1):
    misha,finish,elev,stair,speed,door=l1[0],l1[1],l1[2],l1[3],l1[4],l1[5]
    walktime=abs(misha-finish)*stair
    elevtime=door*2+abs(misha-elev)*speed+abs(misha-finish)*speed
    if elevtime<=walktime:
        return "YES"
    else:
        return "NO"
def answer():
    l1 = [int(x) for x in input().split()]
    print(solution(l1))
answer()