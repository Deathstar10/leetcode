function permute(
  arr: number[],
  ds: number[],
  freq: boolean[],
  output: number[][]
) {
  if (ds.length === arr.length) {
    output.push([...ds]);
    return;
  }

  for (let i = 0; i < arr.length; i++) {
    if (!freq[i]) {
      freq[i] = true;

      ds.push(arr[i]);
      permute(arr, ds, freq, output);

      freq[i] = false;
      ds.pop();
    }
  }
}

function main(arr: number[]) {
  let freq = Array(arr.length).fill(false);
  let output = [];
  permute(arr, [], freq, output);
  console.log(output);
}

main([1, 2, 3]);
