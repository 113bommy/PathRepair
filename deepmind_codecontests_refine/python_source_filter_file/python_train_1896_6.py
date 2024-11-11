def solution(t):
    ans = []
    for i in range(0,len(t)):
        if t[i] < 15 or ((t[i] % 14) <= 6 and (t[i] % 14) != 0): 
            ans.append("YES")
        else:
            ans.append("NO")
    return ans



def main():
    t = int(input())
    nums = list(map(int, input().split()))
    ans = solution(nums)
    for i in range(0,len(ans)):
        print(ans[i])
if __name__ == "__main__":
    main()