
if __name__ == '__main__':
    num_test = int(input())
    for test in range(num_test):
        (q, p1, p2) = (int(x) for x in input().split())
        if p1 <= p2 / 2:
            ans = q * p1
        elif q % 2 == 0:
            ans = int(q / 2) * p2
        else:
            ans = int((q / 2)) * p2 + p1
        print(ans)
        
                        