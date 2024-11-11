def solve():
    N = int(input())
    lst  = list(map(int, input().split()))
    ans = ""

    done = 0
    left = 0
    rigt = len(lst) - 1
    while True:
        if (left <= len(lst)-1 and \
            rigt >= 0 ) and (left <= rigt):

            l,r = lst[left], lst[rigt]
            # if done < lst[left] or done < lst[rigt]:
            if max(l,r) > done:
                if l == r:
                    ans += "L"
                    left += 1
                    continue


                if min(l,r) > done:
                    if l < r :
                        ans += "L"
                        done = l
                        left += 1
                        continue
                    elif r < l:
                        ans += "R"
                        done = r
                        rigt -= 1
                        continue
                else:
                    if l < r:
                        ans += "R"
                        done = r
                        rigt -= 1
                        continue
                    elif r < l:
                        ans += "l"
                        done = l
                        left += 1
                        continue

            else:
                print(len(ans))
                print(ans)
                exit()
        
        else:
            print(len(ans))
            print(ans)
            exit()
            
        
if __name__ == "__main__":
    solve()