def averages(n, heights):
    sm = sum(heights)
    rem = sm % n
    if rem == 0:
        return 0
    else:
        return 1


test_cases = input()
no_of_lines = 2 * int(test_cases)
inp = []
for i in range(no_of_lines):
    inp.append(input().split(' '))



for i in range(0, int(test_cases)):
    n = int(inp[2*i][0])
    heights = [int(j) for j in inp[2*i+1]]
    averages(n, heights)
