#pragma once

#include "engine/core/math/Vector4.h"

extern "C"
{
#include <thirdparty/lua/lua.h>
#include <thirdparty/lua/lualib.h>
#include <thirdparty/lua/lauxlib.h>
}

namespace Echo
{
	// log messages
	void lua_binder_warning(const char* msg);
	void lua_binder_error(const char* msg);

	// lua stack to value
	template<typename T> INLINE T lua_getvalue(lua_State* L, const int index)			{ lua_binder_error("lua stack to value error, unknow c type"); static T st = Variant(); return st; }
	template<> INLINE const char* lua_getvalue<const char*>(lua_State* state, int idx){ return lua_tostring(state, idx); }
	template<> INLINE i32 lua_getvalue<i32>(lua_State* state, int idx) { return (i32)lua_tonumber(state, idx); }
	template<> INLINE ui32 lua_getvalue<ui32>(lua_State* state, int idx) { return (ui32)lua_tonumber(state, idx); }

	// lua operate
	int lua_get_tables(lua_State* luaState, const StringArray& objectNames, const int count);
	int lua_get_upper_tables(lua_State* luaState, const String& objectName, String& currentLayerName);

	// lua push vlaue to stack
	template<typename T> INLINE void lua_pushvalue(lua_State* L, T value) { lua_binder_error("lua stack to value error, unknow c type"); }
	template<> INLINE void lua_pushvalue<const char*>(lua_State* state, const char* value) { lua_pushfstring(state, value); }
	template<> INLINE void lua_pushvalue<bool>(lua_State* state, bool value) { lua_pushboolean(state, value); }
	template<> INLINE void lua_pushvalue<i32>(lua_State* state, i32 value) { lua_pushinteger(state, value); }
	template<> INLINE void lua_pushvalue<ui32>(lua_State* state, ui32 value) { lua_pushinteger(state, value); }
}