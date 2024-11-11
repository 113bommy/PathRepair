def sum_without_i(l, ind):
    sum  = 0
    for i in range(len(l)):
        if not i == ind:
            sum += l[i]
    return sum




def main_function():
    n, s = [int(i) for i in input().split(" ")]
    l = [int(i) for i in input().split(" ")]
    sumof= sum(l)
    for j in range(len(l)):
        if s >= sumof - l[j]:
            return "YES"
    if sumof <= s:
        return "Yes"
    return "No"



print(main_function())