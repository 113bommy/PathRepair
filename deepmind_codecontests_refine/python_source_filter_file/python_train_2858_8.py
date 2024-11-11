from collections import Counter
import copy

def solve():
    Dict={"January":1,"February":2,"March":3,"April":4,"May":5,"June":6,"July":7,"August":8,"September":9,"October":10,"November":11,"December":12}
    string=input()
    left=int(input())
    month=Dict[string]+left
    rem=month%12

    for i in Dict:
        if Dict[i]==rem:
            return i




print(solve())

