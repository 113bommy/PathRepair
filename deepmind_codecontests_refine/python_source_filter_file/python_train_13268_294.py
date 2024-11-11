def main():
    userInp = int(input())
    room = 0
    for i in range(userInp):
        p ,q = list(map(int,input().split()))
        if p < q :
            room +=1

    print(room)

main()