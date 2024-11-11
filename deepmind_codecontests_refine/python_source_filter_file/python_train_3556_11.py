n, m = map(int, input().split())

card = []
max_eaten = 0

for i in range(n):
  card.append(list(input()))

def getItem(arr, row_index, column_index):
  if type(arr) == list and row_index >= 0 and row_index < len(arr):
    row = arr[row_index]
    if type(row) == list and column_index >= 0 and column_index < len(row):
      return row[column_index]

  return None

def card_detour(arr, n_eaten):
  global max_eaten

  for i in range(n):
    for j in range(m):
      if arr[i][j] == "W":
        
        if getItem(arr, i-1, j) == "P":
          arr_copy = arr.copy()
          arr_copy[i][j] = '.'
          arr_copy[i-1][j] = '.'
          card_detour(arr_copy, n_eaten + 1)

        if getItem(arr, i+1, j) == "P":
          arr_copy = arr.copy()
          arr_copy[i][j] = '.'
          arr_copy[i+1][j] = '.'
          card_detour(arr_copy, n_eaten + 1)

        if getItem(arr, i, j-1) == "P":
          arr_copy = arr.copy()
          arr_copy[i][j] = '.'
          arr_copy[i][j-1] = '.'
          card_detour(arr_copy, n_eaten + 1)

        if getItem(arr, i, j+1) == "P":
          arr_copy = arr.copy()
          arr_copy[i][j] = '.'
          arr_copy[i][j+1] = '.'
          card_detour(arr_copy, n_eaten + 1)

        arr_copy = arr.copy()
        arr_copy[i][j] = '.'
        card_detour(arr_copy, n_eaten + 1)
        return

  max_eaten = max(n_eaten, max_eaten)  


card_detour(card, 0)
print(max_eaten)