# Subset Sum

## Understanding the problem

Given: arr: array of integers, sum: target
Generate all subsequences and check if any of them match the target sum.

## Approaches

1. Using a power set to generate all subsequences
2. Using recursion approach for generating subsequences (take and not take approach)

## Recursion Approach

1. Express the problem in the term of indexes (ind, target) and define the base cases
   Here, ind is the current index of the array and target is the sum required t reach using a subsequence from arr[0, ... , ind]
   The base cases are:
     - if target is 0, return true
     - if ind is 0, check return true if (arr[0] = target) else false
2. Explore all possibilities using the indexes
   For every arr[ind], there are two choices: include it in the subarray (take) or exclude it from the subarray (not take).
   not take = f(ind-1, target)
   take = f(ind-1, target-arr[ind])
3. Return the result from the subsequence
   Return (take || not take)

### Pseudocode

```markdown
f(ind, target) {
  // base case
  if (target = 0) return true
  if (ind = 0) return (arr[ind] == target)
  // explore all possibilities
  notTake = f(ind-1, target)
  take = false
  if (arr[ind] < target) take = f(ind-1, target-arr[ind])
  // return result
  return take || notTake
}
main(arr, sum) {
  return f(N-1, sum)
}
```

// Time Complexity: O(2^N)
// Space Complexity: O(target) {recursive stack}

## Memoization Approach

Define a 2D array dp[ind: 0 ... N-1][target: 0 ... sum]

### Pseudocode

```markdown
f(ind, target, dp) {
  // base case
  if (target = 0) dp[ind][target] = return true
  if (ind = 0) return dp[ind][target] = (arr[ind] == target)
  // explore all possibilities
  notTake = f(ind-1, target, dp)
  take = false
  if (arr[ind] < target) take = f(ind-1, target-arr[ind], dp)
  // return result
  return dp[ind][target] = take || notTake
}
main(arr, sum) {
  Initialize dp[ind: 0 ... N-1][target: 0 ... sum]
  return f(n-1, sum, dp)
}
```

// Time Complexity: O(Nxtarget)
// Space Complexity: O(Nxtarget) {dp} + O(target) {recursive stack}

## Tabulation Approach

Define a 2D array dp[ind: 0 ... N-1][target: 0 ... sum]

1. Define base cases
   for (i -> 0 to N-1) dp[i][targ
   dp[0][arr[0]] = true
2. Form the nested loops
   for (ind -> 1 to N-1) {
     for (target -> 0 to sum) {
       notTake = dp[ind-1][target]
       take = dp[ind-1][target-arr[ind]] || false
       dp[ind][target] = take || notTake
     }
   }
3. Return the result
   Return dp[N-1][sum]

### Pseudocode

```markdown
f(arr, sum) {
  n = length(sum)
  Initialize dp[ind: 0 ... N-1][target: 0 ... sum]
  // base cases
  for (i -> 0 to N-1) dp[i][targ
  dp[0][arr[0]] = true
  // form the nested loops
  for (ind -> 1 to N-1) {
    for (target -> 0 to sum) {
      notTake = dp[ind-1][target]
      take = dp[ind-1][target-arr[ind]] || false
      dp[ind][target] = take || notTake
    }
  }
  return dp[N-1][sum]
}
```

// Time Complexity: O(Nxtarget)
// Space Complexity: O(Nxtarget) {dp}
