MAX = 10**15+1

def find_next_n(n):
    cand = []
    n_str = str(n)
    n_list = list(n_str)
    for i in range(1,len(str(n))+1):
        n_list[-i] = '9'
        cand.append(int("".join(n_list)))
    cand_result = [num/snuke(num) for num in cand]
    min_idx = cand_result.index(min(cand_result))

    return cand[min_idx]
    
    
def snuke(num):
    ans = 0
    while num//10 != 0:
        ans += num%10
        num = num//10
    return ans + num

def main():
    K = int(input())
    if K<10:
        for i in range(1,K+1):
            print(i)
    else:
        n = 10
        for i in range(1,K+1):
            print(i)
        for i in range(10,K+1):
            ans = find_next_n(n)
            print(ans)
            n = ans+i
            
            if n>MAX:
                break
    
    
if __name__ == "__main__":
    main()