# MinifyJPEG
This repo is a quick test harness of the magickminify library for CS6200 project 4.

## Purpose
The magickminify library resamples a source image at 25% of the original size.

## Details.
The only interesting aspect here is that we don't know the size of the output file until it's converted. The size is returned by the magickminify function in the final parameter.

Magickminify also allocates memory for the output and we must free it.