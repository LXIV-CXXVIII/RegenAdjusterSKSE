#pragma once

namespace Loki {

	static bool SetGMST(const char* a_setting, float a_set) {

		if (auto set = RE::GameSettingCollection::GetSingleton()) {
			if (auto setting = set->GetSetting(a_setting)) {
				setting->data.f = a_set;
				return true;
			} else {
				logger::info("Invalid GMST ptr");
				return false;
			}
		} else {
			logger::info("Invalid SettingCollection ptr");
			return false;
		}

	};

};