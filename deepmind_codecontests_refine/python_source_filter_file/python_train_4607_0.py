def main():
    test_cases = int(input())
    for _ in range(test_cases):
        a,b = [int(num) for num in input().split()]
        print(a+b)