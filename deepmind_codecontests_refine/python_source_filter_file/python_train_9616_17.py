if __name__ == '__main__':
      _ = input()
      numbers = [int(s) for s in input().split()]
      odd_numbers = [n for n in numbers[:3] if n % 2 != 0]
      odd_more = len(odd_numbers) >= 2
      remainder = int(odd_more)
      for i, n in enumerate(numbers):
            if n % 2 != remainder:
                  print(i)