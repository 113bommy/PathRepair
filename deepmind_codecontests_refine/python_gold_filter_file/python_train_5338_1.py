def main(prices,n):
    min_price = sorted(prices)
    max_price = sorted(prices,reverse=True)
    res = []
    i = j = 0
    round1 = 1 
    while len(res) != n:
        if round1 == 1:
            res.append(max_price[i])
            i += 1
            round1 = 0
        else:
            res.append(min_price[j])
            j += 1
            round1 = 1
    count = 0
    for i in range(1,n-1):
        if res[i-1] > res[i] < res[i+1]:
            count += 1        
    return count,res

if __name__ == '__main__':
    n = int(input())
    prices = list(map(int,input().split()))
    count,order = main(prices,n)
    print(count)
    print(*order)
