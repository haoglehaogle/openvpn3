//    OpenVPN -- An application to securely tunnel IP networks
//               over a single port, with support for SSL/TLS-based
//               session authentication and key exchange,
//               packet encryption, packet authentication, and
//               packet compression.
//
//    Copyright (C) 2012-2015 OpenVPN Technologies, Inc.
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License Version 3
//    as published by the Free Software Foundation.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program in the COPYING file.
//    If not, see <http://www.gnu.org/licenses/>.

// Client tun setup base class for Windows

#ifndef OPENVPN_TUN_WIN_CLIENT_SETUPBASE_H
#define OPENVPN_TUN_WIN_CLIENT_SETUPBASE_H

#include <windows.h> // for HANDLE

#include <openvpn/common/destruct.hpp>
#include <openvpn/common/stop.hpp>
#include <openvpn/tun/builder/capture.hpp>

namespace openvpn {
  namespace TunWin {
    struct SetupBase : public DestructorBase
    {
      typedef RCPtr<SetupBase> Ptr;

      OPENVPN_EXCEPTION(tun_win_setup);

      virtual HANDLE establish(const TunBuilderCapture& pull,
			       Stop* stop,
			       std::ostream& os) = 0;
    };

    struct SetupFactory : public RC<thread_unsafe_refcount>
    {
      typedef RCPtr<SetupFactory> Ptr;

      virtual SetupBase::Ptr new_setup_obj() = 0;
    };
  }
}

#endif
