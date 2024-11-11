

if __name__ == "__main__":
    b, g = map(int, input().split())
    boys = list(map(int, input().split()))
    girls = list(map(int, input().split()))

    boyStatus = [0] * b
    girlStatus = [0] * g

    if len(boys) > 1:
        for i in range(0, boys[0]):
            boyStatus[boys[i+1]] = 1
    
    if len(girls) > 1:
        for i in range(0, girls[0]):
            girlStatus[girls[i+1]] = 1

    for i in range(0, b*g):
        if boyStatus[i%b] == 0 and girlStatus[i%g] == 0:
            continue
        else:
            boyStatus[i%b] = 1
            girlStatus[i%g] = 1
    
    if sum(boyStatus) + sum(girlStatus) == b + g:
        print('Yes')
    else:
        print('No')