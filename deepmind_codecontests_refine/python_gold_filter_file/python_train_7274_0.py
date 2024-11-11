import bisect
def main():
    m,n  = list(map(int,input().split()))
    if n==0:
        exit()
    W = [int(input()) for _ in range(n)]

    w_total = 0
    w_sum =[]
    for w in W:
        w_total+=w
        w_sum.append(w_total)

    def judge(shelf_length):
        last_val = 0
        for i in range(m):
            _index= bisect.bisect_right(w_sum,last_val+shelf_length)
            #print(_index)
            if _index == n:
                return True
            if _index == 0:
                return False
            last_val =w_sum[ _index-1]
        return False


    def nibun(func ,min_ ,max_ ):
        left = min_
        right= max_
        while not(left==right):
            mid = (left+right) //2
            tmp = func(mid)
            if tmp:
                right = mid
            else:
                left = mid+1
        return left

    print(nibun(judge,0,1500009))

while True:
    main()