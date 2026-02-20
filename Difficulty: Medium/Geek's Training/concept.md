# Geek's Training / Ninja's Training

## Understanding the Problem

The geek/ninja can perform one of 3 tasks: A,B,C. Each task has a certain number of points attatched to it, which changes everyday. This continues for N days.
The objective is to maximize the number of points, considering that the geek cannot perform the same task on sonsecutive days.

## Greedy Approach

First Day: A(10), B(50), C(1)
Second Day: A(5), B(100), C(11)

If we take a greedy approach, traversing from initial day to final day, total = B1 + C2 = 50 + 11 = 61.
But we can clearly see the highest total here is A1 + B2 = 10 + 100 = 110.

**Thus we observe that the greedy approach fails in this problem**

## Recursion Approach

The 3 steps to approaching a problem with recursion is:

1. Attach an index to subproblems (here, every index represents a day).
2. Perform operations using that index and what it represents.
3. Choose max/min depending on situation (here, max total points).

Here, let us consider a top down approach: Day N-1 to 0.
But when considering what to do on day I (1 <= I <= N-1), we need to know what task was done on day I-1.
Thus, we need to add another variable to index: **last**. So, within the index, it consists of **day** (represents day of operation) and **last** (represents task performed in the immediate previous day).
So, the last can be:
- 0 (task A)
- 1 (task B)
- 2 (task C)
- 3 (No particular task)

Initial recursion call: f(N-1, 3). This returns the maximum points for all tasks from day 0 to day N-1, given no tasks were performed on day N-1 yet.
On the contrary, f(N-1, 1) would return the maximum points for all tasks from day 0 to day N-1, given task 1 is being performed on day N-1.
So, f(I, 3) = max(f(I, 0), f(I, 1), f(I, 2)).

### Pseudocode

```markdown
f(day, last) {
  if (day == 0) {
    max_point = 0
    for (i = 0 -> 2) {
      if (i != last) max_point = max(max_point, task[0][i])
    }
    return max_point
  }
  max_points = 0
  for (i = 0 -> 2) {
    if (i != last {
      points = task[day][i] + f(day-1, i)
      max_points  max(max_points, points)
    }
  }
  return max_points
}
```

## Top Down Dynamic Programming

For this, we will need to initialize an array: dp[day: 0...N-1][last: 0...3] with -1 in each cell.

### Pseudocode

```markdown
f(day, last) {
  if (day == 0) {
    max_point = 0
    for (i = 0 -> 2) {
      if (i != last) max_point = max(max_point, task[0][i])
    }
    return dp[day][last] = max_point
  }
  if (dp[day][last] != -1) return dp[day][last]
  max_points = 0
  for (i = 0 -> 2) {
    if (i != last {
      points = task[day][i] + f(day-1, i)
      max_points  max(max_points, points)
    }
  }
  return dp[day][last] = max_points
}
```

Time Complexity = O(N*4*3)
Space Complexity = O(N) {stack space} + O(N*4)

## Bottom Up Dynamic Programming

This approach is considered to eliminate stack space emerging from recursion.
The approach applied here is tabulation.
Here too, we initialize an array: dp[day: 0...N-1][last: 0...3] with -1 in each cell.

```markdown
// Define base case
dp[0][0] = max(task[0][1], task[0][2])
dp[0][1] = max(task[0][0], task[0][2])
dp[0][2] = max(task[0][1], task[0][0])
dp[0][3] = max(dp[0][0], dp[0][1], dp[0][2])
// Calculate rest of the cases
for (day = 1 -> N-1) {
  for (last = 0 -> 3 ) {
    max_points = 0
    for (i = 0 -> 2) {
      if (i != last) {
        points = task[day][i] + dp[day-1][i]
        max_points  max(max_points, points)
      }
    }
    dp[day][last] = max_points
  }
}
return dp[N-1][3]
```

Time Complexity = O(N*4*3)
Space Complexity = O(N*4)

## Space Optimization

Initialize an array: dp[last: 0...3]

```markdown
// Define base case
dp[0] = max(task[0][1], task[0][2])
dp[1] = max(task[0][0], task[0][2])
dp[2] = max(task[0][1], task[0][0])
dp[3] = max(dp[0], dp[1], dp[2])
// Calculate rest of the cases
for (day = 1 -> N-1) {
  Initialize array: temp[last: 0...3]
  for (last = 0 -> 3 ) {
    max_points = 0
    for (i = 0 -> 2) {
      if (i != last) {
        points = task[day][i] + dp[i]
        max_points = max(max_points, points)
      }
    }
    temp[last] = max_points
  }
  dp = temp
}
return dp[N-1][3]
```

Time Complexity = O(N*4*3)
Space Complexity = O(4)
