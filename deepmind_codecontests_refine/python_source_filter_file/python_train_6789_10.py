#https://codeforces.com/contest/1288/problem/B
def main():
    print("START")
    t = int(input())
    #print(t)
    for i in range(t):
        v = input()
        #print(repr(v))
        v = v.split(' ')
        #print(repr(v))
        A = int(v[0])
        B = int(v[1])
        #print(A, B)
        res = get_count_2(A, B)
        print(res)

def get_count_2(A, B):
    count = 0
    n = 1
    while True:
        y = 10**n - 1
        if y > B:
            break
        conc_max = str(A) + str(B)
        conc_max_int = int(conc_max)
        max_x = min(conc_max_int // y, A)
        if max_x < 1:
            break
        count += max_x
        n += 1
    return count

main()
