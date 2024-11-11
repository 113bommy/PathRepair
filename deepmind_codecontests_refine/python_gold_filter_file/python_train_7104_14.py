import collections
import operator


if __name__ == "__main__":
    for _ in range(int(input())):
        n, k, m = [int(i) for i in input().split(" ")]
        s = ""
        while m + k + n >0 :
            if s == "":
                if m > 0:
                    s += "11"
                    m -= 1
                elif n > 0:
                    s += "00"
                    n -= 1
                else :
                    s += "10"
                    k -= 1


            else:
                if s[-1] == "1":
                    if m > 0:
                        s += "1"
                        m -= 1
                    else:
                        s += "0"
                        k -= 1
                else:
                    if n > 0:
                        s += "0"
                        n -= 1
                    else:
                        s += "1"
                        k -= 1


        print(s)







        


                
   