
def main_function():
    input_data = [[int(i) for i in input().split(" ")] for k in range(int(input()))]
    for i in input_data:
        k , x = i
        print(9 ** k + x)




main_function()