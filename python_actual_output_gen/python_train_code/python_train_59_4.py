import sys
nb_users = 0
total = 0
for command in sys.stdin:
  if '+' in command:
    nb_users += 1
  elif '-' in command:
    nb_users -= 1
  elif ':' in command:
    total += len(command.split(':')[1]) * nb_users
print(total)   