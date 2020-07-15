#pragma once
#include "util.h"

class gtav_cheats
{
private:
	r_hwnd m_hwnd;			//gtav���ھ��
	r_dword m_pid;			//gtav����ID
	r_handle m_proc;		//gtav���̾��
	r_hmodue m_mod;		//gtav��Ҫģ��

private:
	long		ADDRESS_WORLD = 0;
	long		ADDRESS_BLIP = 0;
	long		ADDRESS_AMMO = 0;
	long		ADDRESS_MAGAZINE = 0;
	long		ADDRESS_TUNABLE = 0;
	long		ADDRESS_WEAPON = 0;
	long		ADDRESS_GLOBAL = 0;
	long		ADDRESS_PLAYER_LIST = 0;
	long		ADDRESS_REPLAY_INTERFACE = 0;

private:
	r_dword_ptr m_dwpWorldBase = 0;
	r_dword_ptr m_dwpTunableBase = 0;
	r_dword_ptr m_dwpGlobalBase = 0;

	r_dword_ptr m_dwpReplayInterfaceBase = 0;
	r_dword_ptr m_Replay_dwpPedInterface = 0;
	r_dword_ptr m_Replay_dwpPedList = 0;

	r_dword_ptr m_dwpPlayerBase = 0;
	r_dword_ptr m_Player_dwpPosBase = 0;
	r_dword_ptr m_Player_dwpPlayerInfo = 0;
	r_dword_ptr m_Player_dwpAttackerBase = 0;

	r_dword_ptr m_dwpVehicleBase = 0;
	r_dword_ptr m_Vehicle_dwpPosBase = 0;
	r_dword_ptr m_Vehicle_dwpHandling = 0;

	r_dword_ptr m_dwpWeaponBase = 0;
	r_dword_ptr m_dwpWeaponManager = 0;
	r_dword_ptr m_dwpWeaponCur = 0;
	r_dword_ptr m_dwpAmmoInfo = 0;

private:
	std::vector<hash_table> m_queue;
	inline void dStatPushBack(unsigned int _hash, int _value) { m_queue.push_back({ _hash,_value }); }

private:
	bool m_show = true;

	bool m_state_unlimited_endurance = true;
	bool m_state_npc_ignore_player = true;
	bool m_state_player_god_mode = true;
	bool m_state_never_fall = true;
	bool m_state_fake_dead_hide = true;
	bool m_state_vehicle_god_mode = true;
	bool m_state_infinite_jet = true;
	bool m_state_super_weapon_damage = true;
	bool m_state_unlimited_ammo = true;
	bool m_state_space_based_gun_without_cooling = true;
	bool m_state_unlock_bunker_research = true;
	bool m_state_anti_AFK_kick_out = true;

private:
	//����ָ�����Ƶ�mod
	r_hmodue get_mod_addr(const r_wchar* str);

	//���µ�ַ�б�
	void update_addrs();

	//��ʾ�˵�
	void show_menu();

	//��ȡ��ǵ�
	vector_2 get_target_point();

	//��ȡ�����
	vector_3 get_aim_point();

	//��ʼ����
	void start_move(vector_3 dest);

private:
	//��ȡ�ڴ�
	template<class T>
	T read(r_dword_ptr addr)
	{
		T result;
		r_size_t size = sizeof(T);
		r_size_t finish = 0;
		r_dword old_protect = 0;

		VirtualProtectEx(m_proc, (LPVOID)addr, size, PAGE_EXECUTE_READWRITE, &old_protect);
		ReadProcessMemory(m_proc, (LPCVOID)addr, &result, size, &finish);
		VirtualProtectEx(m_proc, (LPVOID)addr, size, old_protect, &old_protect);

		return result;
	}

	//д���ڴ�
	template<class T>
	void write(r_dword_ptr addr, T buffer)
	{
		r_size_t size = sizeof(T);
		r_size_t finish = 0;
		r_dword old_protect = 0;

		VirtualProtectEx(m_proc, (LPVOID)addr, size, PAGE_EXECUTE_READWRITE, &old_protect);
		WriteProcessMemory(m_proc, (LPVOID)addr, &buffer, size, &finish);
		VirtualProtectEx(m_proc, (LPVOID)addr, size, old_protect, &old_protect);
	}

private:
	//���͵�Ŀ���
	void move_to_target();

	//���͵������
	void move_to_aim();

	//ȡ��ͨ���ȼ�
	void clear_wanted();

	//��ɱ
	void kill_self();

	//���������ؾ�
	void sit_in_personal_vehicle();

	//��������
	void unlimited_endurance(bool state);

	//npc�������
	void npc_ignore_player(bool state);

	//����ϵ�ģʽ
	void player_god_mode(bool state);

	//����ˤ��
	void never_fall(bool state);

	//�����״�����
	void fake_dead_hide(bool state);

	//�����ϵ�ģʽ
	void vehicle_god_mode(bool state);

	//��������
	void infinite_jet(bool state);

	//�޵г����˺�
	void super_weapon_damage(bool state);

	//���޵�ҩ
	void unlimited_ammo(bool state);

	//���������ȴ
	void space_based_gun_without_cooling(bool state);

	//��ʱ�����ر��о�
	void unlock_bunker_research(bool state);

	//��AFK�߳�
	void anti_AFK_kick_out(bool state);

	//�б���Ϣ����
	void handle_queue();

	//����ս�ִ���
	void battle_handle(int tip);

	//�����ؾ�
	void generate_vehicle(unsigned int val);

	//��ɫ����ȫ��
	void full_character_attributes();

	//��ʳ������ȫ��
	void full_body_snacks();

	//�����ĳ����
	void unlock_car_accessories();

	//��������Ϳװ
	void unlock_weapon_paint();

	//����������
	void unlock_wholesale_price();

	//��������
	void unlock_medal();

	//�����·�
	void unlock_clothes();

	//�ĳ�����
	void casino_holocaust(int index);

public:
	gtav_cheats();
	~gtav_cheats();

	//��ʼ��gtav
	void initialize_gtav();

	//��ʼgrav����
	void start_cheats();
};
