#pragma once

#include <Windows.h>
#include <Psapi.h>

#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

//����ͬ�����
using r_hwnd = HWND;
using r_dword = DWORD;
using r_handle = HANDLE;
using r_hmodue = HMODULE;
using r_wchar = WCHAR;
using r_dword_ptr = DWORD_PTR;
using r_size_t = SIZE_T;
using r_dword64 = DWORD64;
using r_byte = BYTE;

//��ؽṹ
struct vector_2
{
	float x;
	float y;
};

struct vector_3
{
	float x;
	float y;
	float z;
};

struct values
{
	float _cur;
	float _max;
};

struct hash_table
{
	unsigned int _hash;
	int _value;
};

//����״̬���
void error_handle(bool state, const char* str = nullptr);

//����״̬��ʾ��ɫ
void cmd_color(bool state, const char* str = nullptr);

//ת��Ϊhash
unsigned int string_to_hash(std::string input, std::string pre = "MP0_");

//ת��
unsigned int joaat(std::string input);

//���������
bool single_check(int key);

//˫�������
bool two_check(int _left, int _right);
