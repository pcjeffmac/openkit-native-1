/**
* Copyright 2018 Dynatrace LLC
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef _CORE_SESSION_H
#define _CORE_SESSION_H

namespace core
{

	///
	/// This class is returned as Session by {@ref OpenKit#createSession(String)} when the {@link OpenKit#shutdown()}
	/// has been called before.
	///
	class NullSession : public api::ISession
	{
	public:

		///
		/// Constructor
		///
		NullSession();

		virtual std::shared_ptr<api::IRootAction> enterAction(const char* actionName) override
		{
			return NULL_ROOT_ACTION;
		}

		virtual void identifyUser(const char* userTag) override
		{
			// intentionally left empty, due to NullObject pattern
		}

		virtual void reportCrash(const char* errorName, const char* reason, const char* stacktrace) override
		{
			// intentionally left empty, due to NullObject pattern
		}

		virtual void end() override
		{
			// intentionally left empty, due to NullObject pattern
		}
	private:
		static const std::shared_ptr<IRootAction> NULL_ROOT_ACTION = std::make_shared<NullRootAction>();

	};
}

#endif