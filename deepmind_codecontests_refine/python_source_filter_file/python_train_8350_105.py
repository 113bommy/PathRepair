if(__name__)=='__main__':
    t=int(input())
    for i in range(t):
        v = [int(x) for x in input().split(' ')]
        h=v[0]
        m=v[1]
        result=(23-h)*60-m
        print(result)
