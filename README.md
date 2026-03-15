# jax-compress

[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/byronknoll/jax-compress/blob/main/jax_compress.ipynb)

Made by Byron Knoll. GitHub repository: https://github.com/byronknoll/jax-compress

### Description
This project started as a JAX/Flax port of [tensorflow-compress](https://github.com/byronknoll/tensorflow-compress).

jax-compress performs lossless data compression using neural networks. It can run on TPUs/GPUs with a large batch size to get a substantial speed improvement. It is made using Colab, which should make it easy to run through a web browser. You can choose a file, perform compression (or decompression), and download the result.

The neural network is trained from scratch during compression and decompression, so the model weights do not need to be stored. Arithmetic coding is used to encode the model predictions to a file.

Feel free to contact me at byron@byronknoll.com if you have any questions.

### Instructions:

Basic usage: configure all the fields in the "Parameters" section and select Runtime->Run All.

Advanced usage: save a copy of this notebook and modify the code.

### Related Projects
*   [tensorflow-compress](https://github.com/byronknoll/tensorflow-compress)
*   [NNCP](https://bellard.org/nncp/)
*   [lstm-compress](https://github.com/byronknoll/lstm-compress)
*   [cmix](http://www.byronknoll.com/cmix.html)

### Benchmarks
These benchmarks were performed using jax-compress v1 with the default parameter settings. v6e-1 TPU was used. Compression time and decompression time are approximately the same.
*   enwik8: compressed to 15,458,356 bytes in 13,699.63 seconds.
*   enwik9: compressed to 113,393,442 bytes in 110,013.19 seconds. Dictionary size: 80,040 bytes. The preprocessed enwik9 file was split into two parts. The "checkpoint" option was used to save/load model weights between processing each part. Article ordering preprocessing was used:
```
cd enwik9-preproc/
make
./enwik9-preproc c enwik9
# After decompression:
./enwik9-preproc d final.dat
```

See the [Large Text Compression Benchmark](http://mattmahoney.net/dc/text.html) for more information about the test files and a comparison with other programs.

### Versions
* v1 - released March 15, 2026. Changes from tensorflow-compress:
  * Added "retraining": similar to NNCP, the model gets periodically retrained using previously processed data
  * Fixed a bug in NNCP preprocessor
