#!/usr/bin/bash

echo "]ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz1234567890[~@#$%^&*()_+{}|:<>?=\;',./-" && echo "]ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz1234567890[~@#$%^&*()_+{}|:<>?=\;',./-" | \
sed -E "s/[]ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz1234567890[~@#$%^&*()_+{}|:<>?=\;',./-]/./g"
