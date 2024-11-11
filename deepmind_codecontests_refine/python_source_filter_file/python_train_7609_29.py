def main():
    count = 0
    sum = 0
    kol = int(input())
    if ((kol >= 1) and (kol <=1000)):
        lst = list(map(int, input().split()))
        if ((len(lst) == kol) and (kol != 1)):
            ls = sorted(lst)
            #print(ls)
            for i in range(len(ls)-1): #item in ls:
                if (len(ls) > 2):
                    min1 = ls[i]  # min(ls)
                    #print(min1, "=min1")
                    # ls.remove(min1)
                    min2 = ls[i + 1]  # min(ls)
                    #print(min2, "=min2")
                    res = int(min2 - min1 - 1)
                    if (res >= 1):
                        sum = sum + res
                        #print(sum)
                        count += 1
                else:
                    pass

            if (count > 0):
                print(sum)
            else:
                print("0")
        elif (kol == 1):
            print("0")

if (__name__ == "__main__"):
    main()
